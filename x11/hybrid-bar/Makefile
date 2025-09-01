PORTNAME=	hybrid-bar
DISTVERSION=	0.4.9
PORTREVISION=	22
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Status bar focused on wlroots Wayland compositors
WWW=		https://github.com/vars1ty/HybridBar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		cargo gnome
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	vars1ty
GH_PROJECT=	HybridBar
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Generic nodes are not supported by procfs(5)
	@${REINPLACE_CMD} -e 's,/proc,${LINUXBASE}&,g' \
		${WRKSRC_crate_lxinfo}/src/info.rs

.include <bsd.port.mk>
