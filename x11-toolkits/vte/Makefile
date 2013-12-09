# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/vte/Makefile 18940 2013-12-08 01:12:24Z kwm $

PORTNAME=	vte
PORTVERSION=	0.26.2
PORTREVISION?=	5
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Gtk 2 based terminal widget with accessibility and I18N support

USE_BZIP2=	yes
NO_STAGE=	yes

.if !defined(REFERENCE_PORT)

RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper

USES=		bison gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomeprefix gtk20 introspection:build ltverhack referencehack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS?=--disable-python \
		--disable-Bsymbolic \
		--disable-freetypetest \
		--disable-static \
		--enable-introspection \
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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvte.so.9

.include <bsd.port.mk>

.endif
