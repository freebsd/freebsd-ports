# New ports collection makefile for:	Terminal
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Terminal
PORTVERSION=	0.4.8
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME:L}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack pkgconfig vte \
		desktopfileutils
USE_XFCE=	configenv libexo
USE_XORG=	x11

CONFIGURE_ARGS=	--without-gnome-default-appsdir
CONFIGURE_ENV+=	ac_cv_prog_AWK="${AWK}"

OPTIONS=	DBUS	"Enable D-BUS support"			on \
		NLS	"Enable Native Language Support"	on

MAN1=		Terminal.1
MANLANG=	"" ca da el es fr gl id it ja pt ru sv ug zh_CN

.include  <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-doc-Makefile.in
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
