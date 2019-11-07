# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#   $MCom: ports/x11/libgnome/Makefile,v 1.135 2010/09/27 20:06:45 kwm Exp $

PORTNAME=	libgnome
PORTVERSION=	2.32.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for GNOME, a GNU desktop environment

USES=	tar:bzip2

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra \
		libpopt.so:devel/popt
RUN_DEPENDS=	rarian-sk-config:textproc/rarian

INSTALL_TARGET=	install-strip
USES+=		bison gettext gmake gnome localbase libtool:keepla pathfix \
		pkgconfig xorg
USE_GNOME=	gnomeprefix intlhack libbonobo gnomevfs2 referencehack
USE_XORG=	xpm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-deinstall

GCONF_SCHEMAS=	desktop_gnome_accessibility_keyboard.schemas \
		desktop_gnome_accessibility_startup.schemas \
		desktop_gnome_applications_at_mobility.schemas \
		desktop_gnome_applications_at_visual.schemas \
		desktop_gnome_applications_browser.schemas \
		desktop_gnome_applications_office.schemas \
		desktop_gnome_applications_terminal.schemas \
		desktop_gnome_applications_window_manager.schemas \
		desktop_gnome_background.schemas \
		desktop_gnome_file_views.schemas \
		desktop_gnome_interface.schemas \
		desktop_gnome_lockdown.schemas \
		desktop_gnome_peripherals_keyboard.schemas \
		desktop_gnome_peripherals_mouse.schemas \
		desktop_gnome_sound.schemas \
		desktop_gnome_thumbnail_cache.schemas \
		desktop_gnome_thumbnailers.schemas \
		desktop_gnome_typing_break.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/libgnome/libgnome-2.0.pc.in
	@${REINPLACE_CMD} -e '/^$$/d' ${WRKSRC}/po/POTFILES.in
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/libgnome/Makefile.in

.include <bsd.port.mk>

.endif
