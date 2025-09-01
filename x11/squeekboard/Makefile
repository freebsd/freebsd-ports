PORTNAME=	squeekboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.43.1
PORTREVISION=	8
CATEGORIES=	x11 wayland

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	db00c0b4eb73.patch:-p1 # https://gitlab.gnome.org/World/Phosh/squeekboard/-/merge_requests/597

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	On-screen keyboard input method for Wayland
WWW=		https://gitlab.gnome.org/World/Phosh/squeekboard

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13_powerpc64=	fails to link: ld: error: undefined symbol: eekboard_context_service_get_overlay

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libfeedback-0.0.so:accessibility/feedbackd \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cargo compiler:c11 gettext-tools gnome meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf gnomedesktop3 gtk30
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
SHEBANG_FILES=	tools/entry.py
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
MESON_ARGS=	-Dstrict=false
GLIB_SCHEMAS=	sm.puri.Squeekboard.gschema.xml
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-entry \
		bin/${PORTNAME}-test-layout \
		share/applications/sm.puri.Squeekboard.desktop \
		share/locale/be/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/bg/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ca/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/cs/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/de/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/el/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/eu/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fa/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fi/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fr/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fur/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/gl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/he/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/hi/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/hr/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ht/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/hu/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/it/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ka/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ko/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/nl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/oc/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/pl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/pt/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/pt_BR/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ro/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ru/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/sl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/sr/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/sv/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/tr/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/uk/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/zh_CN/LC_MESSAGES/${PORTNAME}.mo \
		${NULL}

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/^cargo/s/"$$@"/--verbose --verbose &/' \
		${WRKSRC}/cargo.sh
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=254091
	@${REINPLACE_CMD} -e "/sed/s/'-i',/& '',/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
