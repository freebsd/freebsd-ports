# New ports collection makefile for:	xlockmore
# Date created:		9 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xlockmore
PORTVERSION=	5.04
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-gl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk --without-esound
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+= --enable-kerberos4
KRB4LIB=	-lcom_err
.endif
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+= --enable-kerberos5
CFLAGS+=	-I${KRB5_HOME}/include
KRB5LIB=	-L${KRB5_HOME}/lib
.endif
USE_X_PREFIX=	yes
USE_XPM=	yes
MAN1=		xlock.1

WITH_MESAGL?=	yes
.if ${WITH_MESAGL} == yes
CONFIGURE_ARGS+=	--with-mesa
MESALIB=	${PTHREAD_LIBS}
USE_MESA=	yes
.else
CONFIGURE_ARGS+=	--without-mesa --without-opengl
.endif
CONFIGURE_ENV+=		XLOCKLIBS="${KRB5LIB} ${KRB4LIB} ${MESALIB}"

.include <bsd.port.pre.mk>

.if defined(WITH_DISABLE_ALLOW_ROOT)
CONFIGURE_ARGS+=	--disable-allow-root
.endif

.if ${XFREE86_VERSION} >= 4
post-configure:
	${PERL} -pi -e 's/-lXdpms//g' ${WRKSRC}/modes/Makefile
.endif

.include <bsd.port.post.mk>
