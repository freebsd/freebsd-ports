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
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
LIB_DEPENDS=	smbclient:${PORTSDIR}/net/samba-libsmbclient

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_OPENLDAP=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE

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
USE_MOTIF=	yes
PLIST_APPEND+=	plist.motif
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

post-install:
	${LOCALBASE}/bin/genkdmconf --no-old --in ${PREFIX}/share/config/kdm/default
	${LOCALBASE}/bin/genkdmconf --no-backup --no-old-scripts --in ${PREFIX}/share/config/kdm
	${RM} -f ${PREFIX}/share/apps/konsole/linux.desktop
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
