#include <QtGui/QApplication>
//#include <QWindowsMime>
#include "tibiaeditor.h"
#include "resourcehandler.h"
#include "formathandler.h"

/*#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>*/

#ifndef NO_STARTUP
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#endif

TibiaHandler g_tibiaHandler;
ResourceHandler g_resourceHandler;
FormatHandler g_formatHandler;

Q_DECLARE_METATYPE( ResourceList )
Q_DECLARE_METATYPE( ItemList )

int main( int argc, char *argv[] )
{
    //_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    QApplication application( argc, argv );
    QCoreApplication::setApplicationVersion( "6.7" );
    QCoreApplication::setApplicationName( "Tibia Editor" );
    QCoreApplication::setOrganizationName( "Demonic Applications" );

    qRegisterMetaType<ResourceList>( "ResourceList" );
    qRegisterMetaType<ItemList>( "ItemList" );

    TibiaEditor window;
    QObject::connect( &application, SIGNAL( focusChanged( QWidget *, QWidget * ) ), &window, SLOT( onFocusChanged( QWidget *, QWidget * ) ) );
    window.show();
    return application.exec();
}
