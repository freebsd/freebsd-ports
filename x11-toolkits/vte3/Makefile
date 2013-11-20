# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/vte3/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME?=	vte
PORTVERSION=	0.34.7
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/gnome-pty-helper/vte/}/${PORTVERSION:R}
DISTNAME=	vte-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USE_XZ=		yes
NO_STAGE=	yes

.if !defined(REFERENCE_PORT)
VTE3_SLAVE?=	no

.if ${VTE3_SLAVE}!="yes"
RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper
.endif

LATEST_LINK?=	vte3
USES=		bison gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME?=	gnomeprefix gtk30 ltverhack referencehack introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS?=--disable-python \
		--with-gtk=3.0 \
		--enable-introspection \
		--disable-Bsymbolic \
		--disable-gnome-pty-helper \
		--disable-freetypetest

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
