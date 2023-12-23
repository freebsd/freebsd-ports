PORTNAME=	keybinder
PORTVERSION=	0.3.2
DISTVERSIONPREFIX=	3.0-
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	https://github.com/kupferlauncher/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSIONPREFIX}v${DISTVERSION}/
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for registering keyboard shortcuts
WWW=		https://github.com/engla/keybinder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext-runtime gmake gnome libtool pathfix \
		pkgconfig xorg
USE_GNOME=	gtk30 introspection:build cairo gdkpixbuf2
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xrender

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

VERSION=	"3.0"
PLIST_SUB=	VERSION=${VERSION}

OPTIONS_DEFINE=	EXAMPLES DOCS

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

post-patch-DOCS-off:
	@${REINPLACE_CMD} -E '/GTK_DOC_CHECK|docs/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^SUBDIRS/s, docs,,' ${WRKSRC}/Makefile.am

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}-${VERSION}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}-${VERSION}

.include <bsd.port.mk>
