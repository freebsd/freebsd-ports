# New ports collection makefile for:	kdebase3
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	3.0.5
PORTREVISION=	0
CATEGORIES?=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS+=	xgettext:${PORTSDIR}/devel/gettext \
		${LOCALBASE}/bin/autoconf:${PORTSDIR}/devel/autoconf\
		${LOCALBASE}/bin/automake:${PORTSDIR}/devel/automake

USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--without-ldap --disable-closure
USE_GMAKE=	yes

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

.include <bsd.port.post.mk>
