# $FreeBSD$

PORTNAME=	run_scaled
DISTVERSION=	g20181209
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Run an X application scaled via Xpra (useful on HiDPI screens)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		xpra:x11/xpra \
		xrandr:x11/xrandr \
		Xvfb:x11-servers/xorg-vfbserver

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	kaueraal
GH_TAGNAME=	669993429863a9f6aa53560171ef1fc57f8546f9
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
