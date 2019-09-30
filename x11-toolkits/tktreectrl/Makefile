# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktreectrl
PORTVERSION=	2.4.1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multi-column hierarchical listbox widget

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tk:tea xorg
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
USE_XORG=	x11
TCL_PKG=	treectrl${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's/FreeBSD-\*/&|DragonFly-*/' ${WRKSRC}/configure

.include <bsd.port.mk>
