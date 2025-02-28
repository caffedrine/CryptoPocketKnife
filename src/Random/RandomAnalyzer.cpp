#include "RandomAnalyzer.h"

#include <math.h>
#include "iso8859.h"
#include "randtest.h"
#include "chisq.h"

RandomAnalyzer::RandomAnalyzer(bool binaryMode, const QByteArray &inputData): BinaryMode(binaryMode)
{
    rt_init((int)binaryMode);

    this->AddData(inputData);
}

RandomAnalyzerResult RandomAnalyzer::GetResult()
{
    RandomAnalyzerResult ret;

    ret.BinaryMode = this->BinaryMode;
    ret.TotalCharacterCount = this->TotalCharacterCount;

    rt_end(&ret.Entropy, &ret.ChiSquare, &ret.ArithmeticMean, &ret.MonteCarloValForPi, &ret.SerialCorrelationCoeficient);
    memcpy(this->CharactersCount, ret.CharactersCount, sizeof(ret.CharactersCount));

    return ret;
}

QString RandomAnalyzer::GetResultHumanReadable()
{
    RandomAnalyzerResult result = this->GetResult();

    QString output = "Characters count: " + QString::number(result.TotalCharacterCount) + "\n\n";
    output += "Entropy = " + QString::number( result.Entropy ) + " bits per " + (result.BinaryMode?"bit":"byte") + "[0-8 closer to 8 higher the entropy]\n\n";

    output += "Optimum compression would reduce the size of this " + QString::number(result.TotalCharacterCount) + "  " + (result.BinaryMode?"bit":"byte") + " file by " +
            QString::number((short) ((100 * ((result.BinaryMode ? 1 : 8) - result.Entropy) / (result.BinaryMode ? 1.0 : 8.0)))) + " percent\n\n";

    double chip = pochisq(result.ChiSquare, (result.BinaryMode ? 1 : 255));
    output += "Chi square distribution for " + QString::number(result.TotalCharacterCount) +  " samples is " + QString::number(result.ChiSquare, 'f', 2) + ", and randomly ";
    if (chip < 0.0001) output += "would exceed this value less than 0.01 percent of the times.\n\n";
    else if (chip > 0.9999) output += "would exceed this value more than than 99.99 percent of the times.\n\n";
    else output += "would exceed this value " + QString::number(chip * 100, 'f', 2) + " percent of the times.\n\n";

    output += "Arithmetic mean value of data " +  QString(result.BinaryMode?"bit":"byte") + " is " + QString::number(result.ArithmeticMean, 'f', 4) + " (" + QString::number(result.BinaryMode ? 0.5 : 127.5, 'f', 1) + " = random).\n\n";

    output += "Monte Carlo value for Pi is " + QString::number(result.MonteCarloValForPi, 'f', 9) + " (error " + QString::number(100.0 * (fabs(M_PI - result.MonteCarloValForPi) / M_PI), 'f', 2) + " percent).\n\n";

    output += "Serial correlation coefficient is " + QString(result.SerialCorrelationCoeficient >= -99999 ? QString::number(result.SerialCorrelationCoeficient, 'f', 6) + " (totally uncorrelated = 0.0)." : "undefined (all values equal!).") + "\n";

    return output;
}

void RandomAnalyzer::AddData(const QByteArray &inputData)
{
    int oc;

    for(int i = 0; i < inputData.size(); i++)
    {
        oc = inputData[i];
        unsigned char ocb;

        ocb = (unsigned char) oc;
        this->TotalCharacterCount += this->BinaryMode ? 8 : 1;
        if(this->BinaryMode)
        {
            int b;
            unsigned char ob = ocb;

            for(b = 0; b < 8; b++)
            {
                this->CharactersCount[ob & 1]++;
                ob >>= 1;
            }
        }
        else
        {
            this->CharactersCount[ocb]++;          /* Update counter for this bin */
        }
        rt_add(&ocb, 1);
    }
}

