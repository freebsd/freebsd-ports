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
COMMENT=	Basic applications for the KDE system

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT} \
		xmkmf:${X_IMAKE_PORT}
LIB_DEPENDS=	sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		smbclient:${PORTSDIR}/net/samba-libsmbclient \
		usb:${PORTSDIR}/devel/libusb

CONFLICTS=	kdelibs-3.[0-3]* kdeutils-3.[0-2]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_GETOPT_LONG=yes
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

CONFIGURE_ENV+=	RUN_KAPPFINDER=no kde_cv_utmp_file=/var/run/utmp
CONFIGURE_ARGS+=--without-java			\
		--with-qt-dir=${X11BASE}	\
		--with-xdmdir=${X11BASE}/lib/X11/xdm

OPTIONS=	ARTSWRAPPER "Suid wrapper for aRts, req'd for realtime prio" on

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ARTSWRAPPER)
RUN_DEPENDS+=	artswrapper:${PORTSDIR}/audio/artswrapper
.endif

post-extract:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/mkpamserv
	@${ECHO} "exit 0" >> ${WRKSRC}/mkpamserv

pre-configure:
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/kdeprint/descriptions/Makefile.in

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
	@${CAT} ${FILESDIR}/genkdmconf.sh | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		| ${SED} -e 's,%%X11BASE%%,${X11BASE},g' > ${WRKDIR}/genkdmconf.sh

post-install:
	${INSTALL_DATA} ${FILESDIR}/freebsd.keytab ${PREFIX}/share/apps/konsole/
	${RM} -f ${PREFIX}/share/apps/konsole/linux.desktop
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
	${INSTALL_SCRIPT} ${WRKDIR}/genkdmconf.sh ${PREFIX}/etc/rc.d/
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
