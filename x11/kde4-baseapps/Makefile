# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	This package provides the basic applications for the KDE system

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
LIB_DEPENDS=	smbclient:${PORTSDIR}/net/samba-libsmbclient

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_OPENLDAP=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--without-java			\
		--with-qt-dir=${X11BASE}	\
		--with-xdmdir=${X11BASE}/lib/X11/xdm

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${X11BASE}/include/Xm/Xm.h)
WITH_MOTIF=	yes
.endif # exists(${X11BASE}/include/Xm/Xm.h)

.if defined(WITHOUT_MOTIF)
.undef WITH_MOTIF
CONFIGURE_ARGS+=	--without-motif
.endif # defined(WITHOUT_MOTIF)

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
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		| ${SED} -e 's,%%X11BASE%%,${X11BASE},g'

.include <bsd.port.post.mk>
