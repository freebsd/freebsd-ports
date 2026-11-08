PORTNAME=	hyprland-preview-share-picker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	x11 wayland

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Hyprland screen share picker with window and monitor previews
WWW=		https://github.com/WhySoBad/hyprland-preview-share-picker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell
RUN_DEPENDS=	xdg-desktop-portal-hyprland>0:x11/xdg-desktop-portal-hyprland

USES=		cargo gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	WhySoBad
GH_TUPLE=	hyprwm:hyprland-protocols:3a5c2bd:protocols/lib/hyprland-protocols
USE_GNOME=	gdkpixbuf glib20 gtk40 pango

CARGO_ENV+=	HPSP_GIT_VERSION="${DISTVERSION}-r0-release"

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR_REL}/schema.json

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} schema > \
		${STAGEDIR}${DATADIR}/schema.json

.include <bsd.port.mk>
