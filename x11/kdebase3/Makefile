# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	7
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

RUN_DEPENDS=	${KDE_PREFIX}/env/xdg-env.sh:${PORTSDIR}/misc/kde-xdg-env \
		kompmgr:${PORTSDIR}/x11-wm/kompmgr
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
LIB_DEPENDS=	sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		smbclient:${PORTSDIR}/net/samba-libsmbclient

CONFLICTS=	kdeartwork-3.[2-3]* kdelibs-3.[0-4]* kdeutils-3.[0-2]*

USE_KDELIBS_VER=3

USE_OPENLDAP=	yes
USE_OPENSSL=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	xpm xkbfile xrandr xcursor xscrnsaver
SUB_FILES=	kdm pkg-deinstall pkg-install pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	RUN_KAPPFINDER=no kde_cv_utmp_file=/var/run/utmp
CONFIGURE_ARGS+=--without-java			\
		--with-qt-dir=${LOCALBASE}	\
		--with-xdmdir=${LOCALBASE}/lib/X11/xdm \
		--with-ssl-dir=${OPENSSLBASE}

OPTIONS=	ARTSWRAPPER "Suid wrapper for aRts, req'd for realtime prio" on \
		HAL "Use HAL backend for media:/" on \
		HTDIG "Depend on htdig, used to build manual indices" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-libusb20
.endif

.if !defined(WITHOUT_ARTSWRAPPER)
RUN_DEPENDS+=	artswrapper:${PORTSDIR}/audio/artswrapper
.endif

.if defined(WITH_HTDIG)
RUN_DEPENDS+=	htdig:${PORTSDIR}/textproc/htdig
.endif

.if !defined(WITHOUT_HAL)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-kioslave_media_mediamanager-halbackend.cpp \
		${FILESDIR}/extrapatch-kioslave_media_mediamanager-halbackend.h
LIB_DEPENDS+=	dbus-qt-1.1:${PORTSDIR}/devel/dbus-qt3 \
		hal.1:${PORTSDIR}/sysutils/hal
PLIST_SUB+=	MEDIA=""
.else
CONFIGURE_ARGS+=--without-hal
PLIST_SUB+=	MEDIA="@comment "
.endif

post-extract:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/mkpamserv
	@${ECHO} "exit 0" >> ${WRKSRC}/mkpamserv

post-patch:
.if ${OSVERSION} >= 800100
	@${REINPLACE_CMD} -e 's,usb_revision.h,usbdi.h,g' \
		${WRKSRC}/kcontrol/usbview/usbdevices.h
.endif

pre-configure:
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/kdeprint/descriptions/Makefile.in
	${REINPLACE_CMD} -e "s,applications-merged,kde-applications-merged,g" \
		${WRKSRC}/applnk/Makefile.in
	${REINPLACE_CMD} \
	-E -e '/XftAntialias/s/false/true/g' \
		${WRKSRC}/kcontrol/krdb/krdb.cpp
	${REINPLACE_CMD} \
	-E -e '/htdigbin/s|/usr/bin|${LOCALBASE}/bin|g' \
	-e '/htdigdata/s|/srv/www/htdig|${LOCALBASE}/share/htdig|g' \
	-e '/htsearchpath/s|/srv/www|${LOCALBASE}/www|g' \
		${WRKSRC}/khelpcenter/searchhandlers/khc_htdig.pl.in \
		${WRKSRC}/khelpcenter/searchhandlers/khc_docbookdig.pl.in \
		${WRKSRC}/khelpcenter/searchhandlers/khc_htsearch.pl
	${REINPLACE_CMD} \
		-e 's|-s|-u|g' \
		${WRKSRC}/kioslave/media/services/media_safelyremove.desktop
	${REINPLACE_CMD} \
		-e 's|kgamma.desktop||g' ${WRKSRC}/applnk/old_desktop_files

post-configure:
	${REINPLACE_CMD} -e "s@^\s*Exec=.*\$$@Exec=ElectricEyes@" \
		${WRKSRC}/kappfinder/apps/Graphics/ElectricEyes.desktop
	${REINPLACE_CMD} -e 's/444/644/g' \
		${WRKSRC}/kdesktop/init/Templates/Makefile

post-install:
	${INSTALL_DATA} ${FILESDIR}/freebsd.keytab ${PREFIX}/share/apps/konsole/
	${RM} -f ${PREFIX}/share/apps/konsole/linux.desktop
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
	@${MV} ${PREFIX}/bin/kdm ${PREFIX}/bin/kdm-bin
	@${MV} ${PREFIX}/bin/kdm_config ${PREFIX}/bin/kdm-bin_config
	@${MV} ${PREFIX}/bin/kdm_greet ${PREFIX}/bin/kdm-bin_greet
	@${INSTALL_SCRIPT} ${WRKDIR}/kdm ${PREFIX}/bin
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
