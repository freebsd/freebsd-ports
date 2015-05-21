# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/vte3/Makefile 19957 2014-10-15 11:07:14Z gusi $

PORTNAME?=	vte
PORTVERSION=	0.38.3
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

.if ${VTE3_SLAVE} != yes
BUILD_DEPENDS+= vapigen:${PORTSDIR}/lang/vala \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper
.endif

USES+=		bison gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomeprefix gtk30 referencehack introspection:build
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

post-patch:
.if ${VTE3_SLAVE} != yes
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in
.endif
# borrowed osversion from bsd.ssp.mk
.if ${OSVERSION} < 1000036 && ${ARCH} == i386
	@${REINPLACE_CMD} -e 's|-fstack-protector-strong||g; \
		s|-fstack-protector||g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>

.endif
