# New ports collection makefile for:   fluxspace
# Date created:        20 March 2003
# Whom:                Eirik Nygaard <eirikn@bluezone.no>
#
# $FreeBSD$
#

PORTNAME=      fluxspace
PORTVERSION=   0.0.3
CATEGORIES=    x11-wm
MASTER_SITES=  http://www.isomedia.com/homes/stevencooper/files/

MAINTAINER=    eirikn@bluezone.no
COMMENT=       A window manager and workspace enhancer and integrator

BUILD_DEPENDS=	imlib2-config:${PORTSDIR}/graphics/imlib2 \
		swig:${PORTSDIR}/devel/swig13

.if defined(WITH_IDESK)
RUN_DEPENDS+=	idesk:${PORTSDIR}/x11/idesk
.endif
.if defined(WITH_ROX-FILER)
RUN_DEPENDS+=	rox:${PORTSDIR}/x11-fm/rox-filer
.endif

USE_PYTHON=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=		yes

pre-everything::
	@${ECHO_CMD} "WITH_IDESK	- To install idesk"
	@${ECHO_CMD} "WITH_ROX-FILER	- To install rox-filer"

post-install::
	@${CAT} pkg-message

.include <bsd.port.mk>
