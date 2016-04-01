# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/vte3/Makefile 18941 2013-12-08 01:18:10Z kwm $

PORTNAME?=	vte
PORTVERSION=	0.34.7
PORTREVISION?=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DISTNAME=	vte-${PORTVERSION}
PKGNAMESUFFIX?=	3-290
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Gtk 3 based terminal widget with accessibility and I18N support

USES+=		tar:xz
PORTSCOUT=	ignore:1

.if !defined(REFERENCE_PORT)
VTE3_SLAVE?=	no

.if ${VTE3_SLAVE}!="yes"
RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:x11-toolkits/gnome-pty-helper
.endif

USES+=		bison gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomeprefix gtk30 referencehack intltool introspection:build
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

GLX_CONFIGURE_ON=	--with-glX
GLX_USE=		GL=yes
.endif

PLIST_SUB=	VERSION=2.90

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/profile.d/vte.sh \
		${STAGEDIR}${PREFIX}/etc/profile.d/vte3.sh

.include <bsd.port.mk>

.endif
