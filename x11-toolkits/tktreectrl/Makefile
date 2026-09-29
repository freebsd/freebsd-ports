PORTNAME=	tktreectrl
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-toolkits tk

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multi-column hierarchical listbox widget
WWW=		https://tktreectrl.sourceforge.net/ \
		https://github.com/tcltk-depot/tktreectrl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		tk:tea xorg
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
USE_XORG=	x11

TCL_PKG=	treectrl${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	tcltk-depot

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${TCL_PKG}/lib${TCL_PKG}.so
	${LN} -s lib${TCL_PKG}.so ${STAGEDIR}${PREFIX}/lib/${TCL_PKG}/libtreectrl.so

.include <bsd.port.mk>
