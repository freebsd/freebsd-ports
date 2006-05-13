# ex:ts=8
# Ports collection makefile for:	wxmozilla
# Date created:			Oct 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wxmozilla
PORTVERSION=	0.5.3
PORTREVISION=	9
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embedding Mozilla in wxWidgets

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget
USE_GECKO=	mozilla
WXGTK_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-wx-config=${WXGTK_CONFIG} --enable-python
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-nspr|nspr|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
