# New ports collection makefile for:	kdebase2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	2.1.1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
SOMAJOR=	4
SOMINOR=	0
USE_XPM=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--with-qt-dir=${X11BASE} \
		--without-ldap \
		--disable-closure
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/libkonq/Makefile.in
	${PERL} -pi -e "s@version-info 1:0:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/khelpcenter/Makefile.in
	${PERL} -pi -e "s@version-info 1:1:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/nsplugins/Makefile.in
	${PERL} -pi -e "s@TIME_WITH_SYS_TIME@INVALID_FOO@g" ${WRKSRC}/kioslave/ldap/kldap.h

.include <bsd.port.mk>
