# New ports collection makefile for:	kdebase2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES?=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--without-ldap --disable-closure
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

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

post-configure:
	${PERL} -pi -e "s@444@644@g" ${WRKSRC}/kdesktop/init/Templates/Makefile

post-install:
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd

.include <bsd.port.post.mk>
