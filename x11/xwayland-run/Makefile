PORTNAME=	xwayland-run
PORTVERSION=	0.0.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Run Xwayland and compositor headless
WWW=		https://gitlab.freedesktop.org/ofourdan/xwayland-run

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cage>0:x11-wm/cage \
		xauth:x11/xauth

USES=		meson pkgconfig python shebangfix tar:xz

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	ofourdan

BINARY_ALIAS+=	python3=${PYTHON_VERSION}
SHEBANG_FILES=	src/xwfb-run.py \
		src/xwayland-run.py \
		src/wlheadless-run.py

MESON_ARGS=	-Dcompositor=cage

.include <bsd.port.mk>
