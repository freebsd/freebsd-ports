# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	vte
PORTVERSION=	0.40.2
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME/sources/${PORTNAME:S/gnome-pty-helper/vte/}/${PORTVERSION:R}
DISTNAME=	vte-${PORTVERSION}
PKGNAMESUFFIX?=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USES=		tar:xz

.if !defined(REFERENCE_PORT)
VTE3_SLAVE?=	no
PORTSCOUT=	limitw:1,even

.if ${VTE3_SLAVE} != yes
BUILD_DEPENDS+= vapigen:${PORTSDIR}/lang/vala \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper
.else
# we need gnutls for configure to pass for gnome-pty-helper ..
BUILD_DEPENDS+=	gnutls>=0:${PORTSDIR}/security/gnutls
.endif

USES+=		bison gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gtk30 intltool referencehack introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS?=--disable-python \
		--with-gtk=3.0 \
		--enable-introspection \
		--disable-static \
		--disable-Bsymbolic \
		--disable-gnome-pty-helper \
		--disable-freetypetest
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=2.91

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900007
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-gnome-pty-helper_gnome-utmp.c
.endif

.if ${OSVERSION} < 1000000
CFLAGS+=	-lz
.endif

post-patch:
.if ${VTE3_SLAVE} != yes
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in
.endif
# zlib.pc only is available on 10.1-R and newer.
.if ${OSVERSION} < 1000000
	@${REINPLACE_CMD} -e 's|gio-unix-2.0 zlib|gio-unix-2.0|g' \
		${WRKSRC}/configure
.endif
# borrowed osversion from bsd.ssp.mk
.if ${OSVERSION} < 1000036 && ${ARCH} == i386
	@${REINPLACE_CMD} -e 's|-fstack-protector-strong||g; \
		s|-fstack-protector||g' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|(AM_MAKEFLAGS) install-exec-hook|(AM_MAKEFLAGS)|g' \
		${WRKSRC}/gnome-pty-helper/Makefile.in
	@${REINPLACE_CMD} -e 's|zlib"|"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

.else
PORTSCOUT=	ignore:1
.endif
