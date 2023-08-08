PORTNAME=	sawfish-pager
PORTVERSION=	0.90.3
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.tuxfamily.org/sawfishpager/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Pager for Sawfish window manager
WWW=		https://sawfish.tuxfamily.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	sawfish:x11-wm/sawfish
RUN_DEPENDS=	sawfish:x11-wm/sawfish

USE_GNOME=	gtk20
USES=		gmake gnome pkgconfig tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/sawfish/sawfishpager \
		share/sawfish/lisp/sawfish/wm/ext/pager.jl \
		share/sawfish/lisp/sawfish/wm/ext/pager.jlc
PORTDOCS=	NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sawfish/sawfishpager

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
