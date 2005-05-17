# New ports collection makefile for:	libgnome
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libgnome
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for GNOME, a GNU desktop environment

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack esound \
		gnomevfs2 libxslt
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

SUB_FILES=	pkg-deinstall

GCONF_SCHEMAS=	desktop_gnome_accessibility_keyboard.schemas \
		desktop_gnome_accessibility_startup.schemas \
		desktop_gnome_applications_browser.schemas \
		desktop_gnome_applications_help_viewer.schemas \
		desktop_gnome_applications_terminal.schemas \
		desktop_gnome_applications_window_manager.schemas \
		desktop_gnome_background.schemas \
		desktop_gnome_file_views.schemas \
		desktop_gnome_interface.schemas desktop_gnome_lockdown.schemas \
		desktop_gnome_peripherals_keyboard.schemas \
		desktop_gnome_peripherals_mouse.schemas \
		desktop_gnome_sound.schemas desktop_gnome_thumbnailers.schemas \
		desktop_gnome_typing_break.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/libgnome/libgnome-2.0.pc.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|gnome-data po doc|gnome-data po|g' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
