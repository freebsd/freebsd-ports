# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--disable-ltdl-install		\
		--without-ldap			\
		--disable-closure		\
		${XINERAMA}			\
		--without-java			\
		--with-qt-dir=${X11BASE}	\
		--with-xdmdir=${X11BASE}/lib/X11/xdm

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/mkfontdir)
PLIST_APPEND+=	plist.mkfontdir
.endif # exists(${X11BASE}/bin/mkfontdir)

.if exists(${X11BASE}/include/Xm/Xm.h)
WITH_MOTIF=	yes
.endif # exists(${X11BASE}/include/Xm/Xm.h)

.if defined(WITH_MOTIF)
USE_MOTIF=	yes
PLIST_APPEND+=	plist.motif
.else
pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Motif support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MOTIF=yes\""
	@${ECHO_MSG}
	@${ECHO_MSG} "Motif is used for Netscape plugin compatibility."
	@${ECHO_MSG}
.endif # defined(WITH_MOTIF)

.if exists(${X11BASE}/lib/libfontconfig.so.1)
WITH_FONTCONFIG=yes
.endif

.if defined(WITH_FONTCONFIG)
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
.endif

.if defined(WITHOUT_XINERAMA)
XINERAMA=	--without-xinerama
.else
XINERAMA=	--with-xinerama
pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you don't want to compile with Xinerama support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITHOUT_XINERAMA=yes\""
	@${ECHO_MSG}
.endif # defined(WITH_XINERAMA)

post-extract:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/mkpamserv
	@${ECHO} "exit 0" >> ${WRKSRC}/mkpamserv

post-configure:
	${REINPLACE_CMD} -e "s@genkdmconf --in@genkdmconf --no-old --in@" \
		${WRKSRC}/kdm/kfrontend/Makefile
	${REINPLACE_CMD} -e "s@^\s*Exec=.*\$$@Exec=ElectricEyes@" \
		${WRKSRC}/kappfinder/apps/Graphics/ElectricEyes.desktop
	${REINPLACE_CMD} -e 's/444/644/g' \
		${WRKSRC}/kdesktop/init/Templates/Makefile

post-install:
	${RM} -f ${PREFIX}/share/apps/konsole/linux.desktop
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd

.include <bsd.port.post.mk>
