PORTNAME=	nuklear
DISTVERSION=	4.9.6
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal-state, immediate-mode graphical user interface toolkit

LICENSE=	MIT PD
LICENSE_COMB=	dual

TEST_DEPENDS=	gmake>0:devel/gmake \
		glew>0:graphics/glew \
		glfw>0:graphics/glfw \
		libGLU>0:graphics/libGLU

USES=		localbase

USE_GITHUB=	yes
GH_ACCOUNT=	Immediate-Mode-UI
GH_PROJECT=	Nuklear

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/nuklear.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/nuklear.h ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${WRKSRC}/example && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS}
.for e in canvas extended file_browser skinning
	@cd ${WRKSRC}/example/bin && ./${e}
.endfor

.include <bsd.port.mk>
