# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome-extras/Makefile,v 1.55 2009/11/28 05:59:04 mezz Exp $

PORTNAME=	gnome-extras
PORTVERSION=	2.25.3
PORTREVISION=	15
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python-extras/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnome-python-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GNOME 2

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell \
		libgksu2.so:${PORTSDIR}/sysutils/libgksu \
#		gdl-1.2:${PORTSDIR}/x11-toolkits/gdl

USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_PYTHON=	yes
USE_GNOME=	libgtkhtml pygnome2 libgda4
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--disable-gdl
INSTALL_TARGET=	install-strip

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome
DOCSDIR=	${PREFIX}/share/doc/py-gnome-extras

post-patch:
	@${REINPLACE_CMD} -e 's|$mozpackage-gtkmozembed|$mozpackage|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${EG_DST_DIR}
	cd ${EG_SRC_DIR}; ${COPYTREE_SHARE} . ${STAGEDIR}${EG_DST_DIR}

.include <bsd.port.mk>
