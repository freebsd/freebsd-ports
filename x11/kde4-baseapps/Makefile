# New ports collection makefile for:	kdebase3
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE_DIST_VERSION}
PORTREVISION=	0
CATEGORIES?=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE_kde} \
		${MASTER_SITE_LOCAL_keramik}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:kde \
		${PORTNAME}-keramik-${KERAMIK_DATE}.tar.bz2:keramik
DIST_SUBDIR=	KDE
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.bz2

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--without-ldap --disable-closure
USE_GMAKE=	yes
KERAMIK_DATE=	20021008.1942

MASTER_SITE_LOCAL_keramik=${MASTER_SITE_LOCAL:S@%SUBDIR%/@alane/:keramik@g}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/mkfontdir)
PLIST_SUB+=	MKFONTDIR=""
.else
PLIST_SUB+=	MKFONTDIR="@comment "
.endif

.if exists(${X11BASE}/include/Xm/Xm.h)
WITH_MOTIF=	yes
.endif

.if defined(WITH_MOTIF) && ${WITH_MOTIF} == yes
USE_MOTIF=	yes
PLIST_SUB+=	MOTIF=""
.else
PLIST_SUB+=	MOTIF="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Motif support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MOTIF=yes\""
	@${ECHO_MSG}
	@${ECHO_MSG} "Motif is used for Netscape plugin compatibility."
	@${ECHO_MSG}
.endif

post-extract:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/mkpamserv
	@${ECHO} "exit 0" >> ${WRKSRC}/mkpamserv

.if !defined(WITHOUT_KERAMIK)
WITH_KERAMIK=	yes
.endif # !defined(WITHOUT_KERAMIK)

.if defined(WITH_KERAMIK)
PLIST_SUB+=	KERAMIK=""
KERAMIK_TARBALL=${PORTNAME}-keramik-${KERAMIK_DATE}.tar.bz2
pre-patch:
	@cd ${WRKSRC};\
	${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/${KERAMIK_TARBALL} | ${TAR} xf -;\
	${CAT} ${FILESDIR}/keramik-patch-* | ${PATCH} ${PATCH_ARGS}
.else
PLIST_SUB+=	KERAMIK="@comment "
.endif # !defined(WITH_KERAMIK)

post-patch:
	@${PERL} -pi -e "s@Exec=ee@Exec=ElectricEyes@g" \
		${WRKSRC}/kappfinder/apps/Graphics/ElectricEyes.desktop

pre-configure:
.if ${MACHINE_ARCH} == "alpha"
	${PERL} -pi -e "s@-O2@-O@g" ${WRKSRC}/admin/acinclude.m4.in
.endif
	cd ${WRKSRC}; ${GMAKE} -f Makefile.cvs

post-configure:
	${PERL} -pi -e "s@444@644@g" ${WRKSRC}/kdesktop/init/Templates/Makefile

post-install:
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
.if defined(WITH_KERAMIK)
	@if test -f ${PKGMESSAGE}; then \
		${ECHO}; ${CAT} ${PKGMESSAGE}; ${ECHO}; fi
.endif # defined(WITH_KERAMIK)

.include <bsd.port.post.mk>
