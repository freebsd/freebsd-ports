PORTNAME=	tofi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tiny dynamic menu for Wayland
WWW=		https://github.com/philj56/tofi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo pango
GH_ACCOUNT=	philj56
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-drun \
		bin/${PORTNAME}-run \
		etc/xdg/${PORTNAME}/config \
		share/bash-completion/completions/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME}-drun \
		share/bash-completion/completions/${PORTNAME}-run

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}-drun.1.gz \
			share/man/man1/${PORTNAME}-run.1.gz \
			share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}.5.gz

post-patch:
# Respect PREFIX for system config and *.desktop
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/doc/${PORTNAME}.1.scd \
		${WRKSRC}/src/drun.c

.include <bsd.port.mk>
