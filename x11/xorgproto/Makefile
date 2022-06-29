PORTNAME=	xorgproto
DISTVERSION=	2022.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Window System unified protocol definitions

LICENSE=	MIT

USES=		xorg-cat:proto

NO_ARCH=	yes

CONFIGURE_ARGS=	--without-fop \
		--without-xmlto \
		--without-xsltproc \
		--disable-specs

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${MKDIR} ${WRKSRC}/man

.include <bsd.port.mk>
