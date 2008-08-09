# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	searchclient:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl moc rcc uic dbus qt3support \
		designer network svg qtestlib

USE_FAM=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdelibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e "s,<qfile.h>,<QFile>,;s,<qevent.h>,<QtEvents>,; \
		s,<qapplication.h>,<QApplication>," \
		${WRKSRC}/../apps/konqueror/src/konqbookmarkbar.cpp
	${REINPLACE_CMD} -e 's|<qstringlist.h>|<QStringList>|'\
	    ${WRKSRC}/../apps/nsplugins/plugin_paths.h
	${REINPLACE_CMD} -e "s,<qtimer.h>,<QTimer>,; \
		s,<qwidget.h>,<QWidget>," \
		${WRKSRC}/../apps/nsplugins/viewer/xtevents.h

.include <bsd.port.mk>
