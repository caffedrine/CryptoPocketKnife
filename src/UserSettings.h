#ifndef _USERSETTINGS_H_
#define _USERSETTINGS_H_

#include <QSettings>
#include <QString>

#if !defined(DLL_DECL_SPEC)
#define DLL_DECL_SPEC
#endif

#define UserSettings User_Settings::inst()

class DLL_DECL_SPEC User_Settings
{
public:
    Q_DISABLE_COPY(User_Settings)
    static User_Settings *inst();

    // Location where user can place its custom resources, downloads etx
    QString Get_UserBasePathAbs();
    QString Get_UserDataPathAbs();

    // Get/Set shodan key
    QString Get_OSINT_ShodanApiKey();
    void Set_OSINT_ShodanApiKey(QString newKey);

protected:
    QByteArray encryptData(QByteArray &decrypted);
    QByteArray decryptData(QByteArray &encrypted);


private:
    static User_Settings *instance;
    QSettings *settings {};
    explicit User_Settings();
};


#endif // _USERSETTINGS_H_
