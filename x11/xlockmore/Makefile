# New ports collection makefile for:	xlockmore
# Date created:		9 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xlockmore
PORTVERSION=	5.13
CATEGORIES?=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		http://www.tux.org/~bagleyd/latest/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Like XLock session locker/screen saver, but just more

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk --without-esound
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+=--enable-kerberos4
KRB4LIB=	-lcom_err -lcrypto
.endif
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--enable-kerberos5
CFLAGS+=	-I${KRB5_HOME}/include
KRB5LIB=	-L${KRB5_HOME}/lib
.endif
USE_X_PREFIX=	yes
USE_XPM=	yes
MAN1=		xlock.1

.if ${MACHINE_ARCH} == "amd64"
WITH_MESAGL=	no
.else
WITH_MESAGL?=	yes
.endif
.if ${WITH_MESAGL} == yes
CONFIGURE_ARGS+=	--with-mesa
MESALIB=${PTHREAD_LIBS}
USE_GL=	yes
.else
CONFIGURE_ARGS+=	--without-mesa --without-opengl
.endif

.if defined(WITH_MB)
CONFIGURE_ARGS+=	--enable-use_mb
.endif

.if defined(XLOCKMORE_LANG)
CONFIGURE_ARGS+=	--with-lang=${XLOCKMORE_LANG}
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog
.endif

CONFIGURE_ENV+=		XLOCKLIBS="${KRB5LIB} ${KRB4LIB} ${MESALIB}"

.include <bsd.port.pre.mk>

.if defined(WITH_DISABLE_ALLOW_ROOT)
CONFIGURE_ARGS+=	--disable-allow-root
.endif

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
post-configure:
	${REINPLACE_CMD} -e 's/-lXdpms//g' ${WRKSRC}/modes/Makefile
.endif

.include <bsd.port.post.mk>
