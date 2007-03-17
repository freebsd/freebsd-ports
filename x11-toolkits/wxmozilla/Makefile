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

USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget
USE_GECKO=	mozilla
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--enable-python
USE_WX=		2.4
WX_COMPS=	wx python
WX_CONF_ARGS=	absolute
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-nspr|nspr|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
