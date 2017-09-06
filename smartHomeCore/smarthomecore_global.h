#ifndef SMARTHOMECORE_GLOBAL_H
#define SMARTHOMECORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SMARTHOMECORE_LIBRARY)
#  define SMARTHOMECORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SMARTHOMECORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SMARTHOMECORE_GLOBAL_H
