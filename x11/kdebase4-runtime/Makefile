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
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
LIB_DEPENDS=	smbclient:${PORTSDIR}/net/samba-libsmbclient

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_OPENLDAP=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE
PKGINSTALL=	${WRKDIR}/INSTALL

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--without-java			\
		--with-qt-dir=${X11BASE}	\
		--with-xdmdir=${X11BASE}/lib/X11/xdm

OPTIONS=	ARTSWRAPPER "Suid wrapper for aRts, req'd for realtime prio" on \
		MOTIF       "Support Netscape plugins, requires openmotif" on

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ARTSWRAPPER)
RUN_DEPENDS+=	artswrapper:${PORTSDIR}/audio/artswrapper
.endif

.if !defined(WITHOUT_MOTIF)
RUN_DEPENDS=	nspluginviewer:${PORTSDIR}/www/konqueror-nsplugins
.elseif defined(WITHOUT_MOTIF)
CONFIGURE_ARGS+=	--without-motif
.endif

post-extract:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/mkpamserv
	@${ECHO} "exit 0" >> ${WRKSRC}/mkpamserv

post-configure:
	${REINPLACE_CMD} -e "s@^\s*Exec=.*\$$@Exec=ElectricEyes@" \
		${WRKSRC}/kappfinder/apps/Graphics/ElectricEyes.desktop
	${REINPLACE_CMD} -e 's/444/644/g' \
		${WRKSRC}/kdesktop/init/Templates/Makefile

post-build:
	@${CAT} ${PKGDIR}/pkg-message | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		| ${SED} -e 's,%%X11BASE%%,${X11BASE},g' > ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/pkg-install | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		| ${SED} -e 's,%%X11BASE%%,${X11BASE},g' > ${PKGINSTALL}
	@${CAT} ${FILESDIR}/kdm.sh | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		| ${SED} -e 's,%%X11BASE%%,${X11BASE},g' > ${WRKDIR}/kdm.sh

post-install:
	${RM} -f ${PREFIX}/share/apps/konsole/linux.desktop
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
	${INSTALL_SCRIPT} ${WRKDIR}/kdm.sh ${PREFIX}/etc/rc.d
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
