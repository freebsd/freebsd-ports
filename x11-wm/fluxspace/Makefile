# New ports collection makefile for:   fluxspace
# Date created:        20 March 2003
# Whom:                Eirik Nygaard <eirikn@bluezone.no>
#
# $FreeBSD$
#

PORTNAME=	fluxspace
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A window manager and workspace enhancer and integrator

BUILD_DEPENDS=	imlib2-config:${PORTSDIR}/graphics/imlib2 \
		swig:${PORTSDIR}/devel/swig13

BROKEN=		Checksum mismatch

USE_XLIB=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_IDESK) || exists(${X11BASE}/bin/idesk)
RUN_DEPENDS+=	idesk:${PORTSDIR}/x11/idesk
.endif
.if defined(WITH_ROX-FILER) || exists(${LOCALBASE}/bin/rox)
RUN_DEPENDS+=	rox:${PORTSDIR}/x11-fm/rox-filer
.endif

pre-everything::
	@${ECHO_MSG} "WITH_IDESK	- To install idesk"
	@${ECHO_MSG} "WITH_ROX-FILER	- To install rox-filer"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
