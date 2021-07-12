@ECHO OFF
COLOR
TITLE Deploying application
CLS
SETLOCAL
SET "_QT_DIR_PATH=%1"
IF /I "%_QT_DIR_PATH%" == "" ECHO Qt install dir not found && GOTO Fin
SET "_EXE_FILE_PATH=%2"
IF /I "%_EXE_FILE_PATH%" == "" ECHO Application exe not found && GOTO Fin
SET "_EXE_DIR_PATH=%3"
IF /I "%_EXE_DIR_PATH%" == "" ECHO Application dir not found && GOTO Fin
SET "_QML_FILE_PATH=%4"
IF /I "%_QML_FILE_PATH%" == "" (
    SET _DEP_PARAMS=--plugindir "%_EXE_DIR_PATH%\plugins" --force --compiler-runtime "%_EXE_FILE_PATH%"
) ELSE (
    SET _DEP_PARAMS=--dir "%_EXE_DIR_PATH%\qml" --libdir "%_EXE_DIR_PATH%" --plugindir "%_EXE_DIR_PATH%\plugins" --force --qmldir "%_QML_FILE_PATH%" --compiler-runtime "%_EXE_FILE_PATH%"
)
SET "PATH=%_QT_DIR_PATH%\bin;%PATH%"
IF EXIST "%_EXE_DIR_PATH%\plugins" RD /S /Q "%_EXE_DIR_PATH%\plugins"
IF EXIST "%_EXE_DIR_PATH%\qml" RD /S /Q "%_EXE_DIR_PATH%\qml"
IF EXIST "%_EXE_DIR_PATH%\translations" RD /S /Q "%_EXE_DIR_PATH%\translations"
IF EXIST "%_EXE_DIR_PATH%\languages" RD /S /Q "%_EXE_DIR_PATH%\languages"
IF EXIST "%_EXE_DIR_PATH%\Qt*.dll" DEL /F /Q "%_EXE_DIR_PATH%\Qt*.dll"
IF EXIST "%_EXE_DIR_PATH%\qt.conf" DEL /F /Q "%_EXE_DIR_PATH%\qt.conf"
windeployqt %_DEP_PARAMS%
IF EXIST "%_EXE_DIR_PATH%\qml\translations" MOVE /Y "%_EXE_DIR_PATH%\qml\translations" "%_EXE_DIR_PATH%"
IF EXIST "%_EXE_DIR_PATH%\translations" (
    CD /D "%_EXE_DIR_PATH%"
    REN "translations" "languages"
)
IF %ERRORLEVEL% NEQ 0 ECHO Something wrong happened, deploying process aborted && GOTO Fin
SET "_CONF_FILE_PATH=%_EXE_DIR_PATH%\qt.conf"
> "%_CONF_FILE_PATH%" (
    @ECHO [Paths]
    @ECHO Prefix=.
    @ECHO Binaries=.
    @ECHO Libraries=.
    @ECHO Plugins=plugins
    @ECHO Imports=imports
    @ECHO Qml2Imports=qml
    @ECHO Translations=languages
)
TITLE Finished
CLS
ECHO Deploying process have completed successfully
ECHO Press any key to exit this batch script
GOTO Fin

:Fin
ENDLOCAL
PAUSE
EXIT /B
