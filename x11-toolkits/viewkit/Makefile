# New ports collection makefile for:	Viewkit from Hungry Programming
# Date created:				Aug 2000
# Whom:					peterho@ned.dem.csiro.au
#
# $FreeBSD$
#

PORTNAME=	viewkit
PORTVERSION=	0.00
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/viewkit/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
DISTNAME=	libvk-Apr19-2243

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ViewKit workalike from Hungry Programmers

WANT_AUTOCONF_VER=	253
MOTIFPACKAGE?=	open-motif
USE_X_PREFIX=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-${MOTIFPACKAGE}

post-patch:
	@${REINPLACE_CMD} -e 's/^friend/friend class/' ${WRKSRC}/Vk/VkAction.h \
		${WRKSRC}/Vk/VkApp.h ${WRKSRC}/Vk/VkMenu.h
	@${REINPLACE_CMD} -E 's/\((VkPipe::handleInput)\)/\1/' ${WRKSRC}/VkPipe.C

pre-configure:
	@cd ${WRKSRC}; ${CHMOD} +w configure; ${AUTOCONF}

.include <bsd.port.mk>
