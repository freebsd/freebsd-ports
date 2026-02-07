PORTNAME=	alacarte
PORTVERSION=	3.58.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Menu editor using the freedesktop.org menu specification
WWW=		https://gitlab.gnome.org/GNOME/alacarte

LICENSE=	LGPL20

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

USES=		gettext gmake gnome pkgconfig python tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gnomemenus3 gtk30 pygobject3 libxslt:build
USE_PYTHON=	py3kplist

.include <bsd.port.mk>
