# New ports collection makefile for:	login.app
# Date created:				17 January 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	login.app
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://largo.windowmaker.org/files/Login.app/ \
		http://depot.fsck.ch/mirror/distfiles/
DISTNAME=	Login.app-${PORTVERSION}

MAINTAINER=	ports@fsck.ch
COMMENT=	Graphical login interface for X that is themable

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker \
		PropList.2:${PORTSDIR}/devel/libPropList

WRKSRC=		${WRKDIR}/Login.app-${PORTVERSION:S/.a/-Alpha-/}

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		Login.app.1x

pre-configure:
	@${REINPLACE_CMD} -e \
		's|GNUstep/Applications|GNUstep/Apps|' \
		${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/Scripts/Makefile.am \
		${WRKSRC}/Scripts/Makefile.in \
		${WRKSRC}/Themes/Linux/Makefile.am \
		${WRKSRC}/Themes/Linux/Makefile.in \
		${WRKSRC}/Themes/GNUstep/Makefile.am \
		${WRKSRC}/Themes/GNUstep/Makefile.in \
		${WRKSRC}/Themes/Drone/Makefile.in \
		${WRKSRC}/Themes/Drone/Makefile.am \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/Makefile.am \
		${WRKSRC}/doc/Login.app.1x
	# this replacement is only used to fix cluster builds:
	@${REINPLACE_CMD} -e \
		's|-lWUtil|-lWUtil -lintl|' \
		${WRKSRC}/configure \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/Makefile.am

post-configure:
	@${REINPLACE_CMD} -e \
		's|%%X11BASE%%|${X11BASE}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Scripts/Login.user \
		${WRKSRC}/Scripts/Login.root \
		${WRKSRC}/Scripts/Logout.root \
		${WRKSRC}/Scripts/Startup \
		${WRKSRC}/Preferences \
		${WRKSRC}/src/config.h \
		${WRKSRC}/src/preferences.h \
		${WRKSRC}/doc/Login.app.1x

post-install:
	@${SED} 's|%%X11BASE%%|${PREFIX}|' \
		${FILESDIR}/loginapp.sh > ${PREFIX}/etc/rc.d/loginapp.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/loginapp.sh

.include <bsd.port.mk>
