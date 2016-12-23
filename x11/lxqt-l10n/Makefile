# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-l10n
PORTVERSION=	0.11.1
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Translations of LXQt components

LICENSE=	LGPL21+

RUN_DEPENDS=	liblxqt-l10n>=0.11:devel/liblxqt-l10n \
	lximageqt-l10n>=0.11:graphics/lximageqt-l10n \
	libfmqt-l10n>=0.11:x11/libfmqt-l10n \
	pcmanfmqt-l10n>=0.11:x11-fm/pcmanfmqt-l10n

# Can't use metaport, because we need to fetch tarball
USES=	lxqt tar:xz
USE_LXQT=	lxqt

NO_BUILD=       yes
NO_INSTALL=     yes
NO_MTREE=       yes
NO_ARCH=        yes

.include <bsd.port.mk>
