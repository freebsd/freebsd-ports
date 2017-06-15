# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-terminal
PORTVERSION=	3.18.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 3 Desktop

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		appstream-builder:devel/appstream-glib \
		vala:lang/vala
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		cpe gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	dconf gtk30 intlhack nautilus3 vte3
USE_XORG=	sm ice
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.Terminal.gschema.xml

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		MIGRATION SEARCHPROVIDER
OPTIONS_DEFAULT=	SEARCHPROVIDER
SEARCHPROVIDER_DESC=	Gnome-shell search provider
SEARCHPROVIDER_CONFIGURE_ENABLE=	search-provider
SEARCHPROVIDER_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
SEARCHPROVIDER_RUN_DEPENDS=	gnome-shell:x11/gnome-shell
MIGRATION_CONFIGURE_ENABLE=	migration
MIGRATION_USE=		GNOME=gconf2
MIGRATION_DESC=		Profile migration to gsettings (pulls in gconf2)

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

post-install:
.for i in ca cs de el es fi fr gl hu pt_BR ru
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/help/${i}/gnome-terminal/figures
.endfor

.include <bsd.port.mk>
