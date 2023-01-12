//
/// TODO: Fix thread-unsafe problem
//

#ifndef _RANDOMANALYZER_H_
#define _RANDOMANALYZER_H_

#include <QByteArray>
#include <QString>

struct RandomAnalyzerResult
{
    bool BinaryMode;
    long TotalCharacterCount = 0;
    double CharactersCount[256];
    double Entropy;
    double ChiSquare;
    double ArithmeticMean;
    double MonteCarloValForPi;
    double SerialCorrelationCoeficient;
};

class RandomAnalyzer
{
    bool BinaryMode;
    double CharactersCount[256];
    long TotalCharacterCount = 0;
public:
    RandomAnalyzer(bool binaryMode, const QByteArray &inputData);
    void AddData(const QByteArray &inputData);
    RandomAnalyzerResult GetResult();
    QString GetResultHumanReadable();
};


#endif //_RANDOMANALYZER_H_
