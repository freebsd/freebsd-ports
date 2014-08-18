# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/vte3/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME?=	vte
PORTVERSION=	0.36.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/gnome-pty-helper/vte/}/${PORTVERSION:R}
DISTNAME=	vte-${PORTVERSION}
PKGNAMESUFFIX?=	3
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USES=		tar:xz

.if !defined(REFERENCE_PORT)
VTE3_SLAVE?=	no

.if ${VTE3_SLAVE}!="yes"
RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper
.endif

USES+=		bison gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomeprefix gtk30 referencehack introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS?=--disable-python \
		--with-gtk=3.0 \
		--enable-introspection \
		--disable-static \
		--disable-Bsymbolic \
		--disable-gnome-pty-helper \
		--disable-freetypetest
INSTALL_TARGET=	install-strip

.if !defined(MASTERDIR)
OPTIONS_DEFINE=	GLX
GLX_DESC=	Support for DRI/GLX rendering
.endif

PLIST_SUB=	VERSION=2.90

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
