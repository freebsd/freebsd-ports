# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/vte/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	vte
PORTVERSION=	0.26.2
PORTREVISION?=	4
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USE_BZIP2=	yes
NO_STAGE=	yes

.if !defined(REFERENCE_PORT)

RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper

USES=		bison gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME?=	gnomeprefix gtk20 ltverhack referencehack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS?=--disable-python \
		--disable-Bsymbolic \
		--disable-freetypetest \
		--disable-gnome-pty-helper

.if !defined(MASTERDIR)
OPTIONS_DEFINE=	GLX
GLX_DESC=	Support for DRI/GLX rendering
.endif

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900007
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-gnome-pty-helper_gnome-utmp.c
.endif

.if ${PORT_OPTIONS:MGLX} && !defined(MASTERDIR)
CONFIGURE_ARGS+=	--with-glX
USE_GL=			yes
.endif

.include <bsd.port.mk>

.endif
