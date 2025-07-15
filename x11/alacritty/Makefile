PORTNAME=	alacritty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
CATEGORIES=	x11 wayland

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	GPU-accelerated terminal emulator
WWW=		https://alacritty.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	dejavu>0:x11-fonts/dejavu

USES=		cargo localbase:ldflags python:build
USE_GITHUB=	yes

CARGO_INSTALL_PATH=	alacritty
CARGO_FEATURES+=	--no-default-features
CARGO_CARGOTOML=	${WRKSRC}/${PORTNAME}/Cargo.toml

# For xcb crate
BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/alacritty \
		etc/bash_completion.d/alacritty.bash \
		share/fish/completions/alacritty.fish \
		share/metainfo/org.alacritty.Alacritty.appdata.xml \
		share/pixmaps/Alacritty.svg \
		share/zsh/site-functions/_alacritty \
		${DESKTOPDIR}/Alacritty.desktop

OPTIONS_DEFINE=	MANPAGES
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	WAYLAND X11
OPTIONS_DEFAULT=	MANPAGES WAYLAND X11

BACKEND_DESC=	Display backend

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/alacritty.1.gz \
			share/man/man1/alacritty-msg.1.gz \
			share/man/man5/alacritty.5.gz \
			share/man/man5/alacritty-bindings.5.gz

WAYLAND_VARS=	CARGO_FEATURES+=wayland
X11_USES=	xorg
X11_USE=	XORG=xcb
X11_VARS=	CARGO_FEATURES+=x11

post-build-MANPAGES-on:
	scdoc < ${WRKSRC}/extra/man/alacritty.1.scd > ${WRKSRC}/alacritty.1
	scdoc < ${WRKSRC}/extra/man/alacritty-msg.1.scd > ${WRKSRC}/alacritty-msg.1
	scdoc < ${WRKSRC}/extra/man/alacritty.5.scd > ${WRKSRC}/alacritty.5
	scdoc < ${WRKSRC}/extra/man/alacritty-bindings.5.scd > ${WRKSRC}/alacritty-bindings.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/extra/linux/Alacritty.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/logo/alacritty-term.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/Alacritty.svg
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/extra/linux/org.alacritty.Alacritty.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/extra/completions/alacritty.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/extra/completions/alacritty.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/extra/completions/_alacritty \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/alacritty.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/alacritty.1
	${INSTALL_MAN} ${WRKSRC}/alacritty-msg.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/alacritty-msg.1
	${INSTALL_MAN} ${WRKSRC}/alacritty.5 \
		${STAGEDIR}${PREFIX}/share/man/man5/alacritty.5
	${INSTALL_MAN} ${WRKSRC}/alacritty-bindings.5 \
		${STAGEDIR}${PREFIX}/share/man/man5/alacritty-bindings.5

.include <bsd.port.mk>
