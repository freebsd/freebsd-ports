PORTNAME=	ctwm
DISTVERSION=	4.0.3
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://www.ctwm.org/dist/ \
		https://distfiles.over-yonder.net/ctwm/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extension to twm, with support for multiple virtual screens

LICENSE=	MIT

USES=		cmake jpeg tar:xz xorg
USE_XORG=	x11 xext xt ice sm xpm xmu

OPTIONS_DEFINE=	DOCS EXAMPLES

# mtree isn't run in poudriere, so /usr/local/ isn't all setup like it
# should be, so we have to force this
CMAKE_ARGS=	-DMANDIR:STRING="${PREFIX}/share/man"

.include <bsd.port.mk>
