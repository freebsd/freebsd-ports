# New ports collection makefile for:	xlockmore
# Date created:		9 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xlockmore
PORTVERSION=	5.00
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-gl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk --without-esound
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+= --enable-kerberos4
.endif
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+= --enable-kerberos5
.endif
USE_X_PREFIX=	yes
USE_XPM=	yes
MAN1=		xlock.1

.include <bsd.port.pre.mk>

# .if ${OSVERSION} > 300000
# CONFIGURE_ARGS+= --with-libraries=/usr/lib/aout
# .endif

WITH_MESAGL?=	yes
.if ${WITH_MESAGL} == yes
CONFIGURE_ARGS+=	--with-mesagl
USE_MESA=	yes
.else
CONFIGURE_ARGS+=	--without-mesagl
.endif

.if ${XFREE86_VERSION} >= 4
post-configure:
	${PERL} -pi -e 's/-lXdpms//g' ${WRKSRC}/modes/Makefile
.endif

.include <bsd.port.post.mk>
