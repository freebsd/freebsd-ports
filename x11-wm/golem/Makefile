# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	golem
PORTVERSION=	0.0.6
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small window manager with themes and plugins

LICENSE=	BSD

OPTIONS_DEFINE=	ESOUND XINERAMA
OPTIONS_DEFAULT=	XINERAMA

USES=		perl5 gmake tar:bzip2
USE_PERL5=	build
USE_XORG=	xpm
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-i18n
MAKE_ARGS=	DEVEL=1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif
.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-sound
PLIST_SUB+=	ESOUND=""
.else
PLIST_SUB+=	ESOUND="@comment "
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
CONFIGURE_ARGS+=--enable-xinerama
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/cl_thread.c/d' ${WRKSRC}/complib/user/Makefile

# avoid using standard MAKE_ENV
do-build:
	@cd ${BUILD_WRKSRC}; \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@cd ${INSTALL_WRKSRC}; \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
