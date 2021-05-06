# Created by: thierry@pompo.net

PORTNAME=	tktable
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/tk/Tk/}${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Table/matrix widget extension to Tk

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES+=		tk:tea
TCL_PKG=	${DISTNAME}
USE_LDCONFIG=	${PREFIX}/lib/${DISTNAME}
TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's/FreeBSD-\*/FreeBSD-*|DragonFly-*/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
