# Created by: bsam
# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.14.7
PORTREVISION=	5
CATEGORIES=	x11-toolkits linux
BIN_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-engines-2.16.1-1.fc10${EXTRACT_SUFX} \
		gtk-murrine-engine-0.53.1-3.fc10${EXTRACT_SUFX} \
		gtk-nodoka-engine-0.7.2-1.fc10${EXTRACT_SUFX} \
		gtk-qt-engine-1.1-2.fc10${EXTRACT_SUFX} \
		gtk-rezlooks-engine-0.6-6.fc9${EXTRACT_SUFX} \
		gtk-xfce-engine-2.4.3-1.fc10${EXTRACT_SUFX} \
		pixman-0.12.0-3.fc10${EXTRACT_SUFX} \
		jasper-libs-1.900.1-8.fc9${EXTRACT_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux Fedora 10)

CONFLICTS=	linux-gtk2-[0-9]* linux-f8-gtk2-[0-9]*

USES=		linux:f10
# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
USE_LINUX=	atk jpeg pango png tiff xorglibs
USE_LINUX_RPM=	nolib

RPMVERSION=	9.fc10
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		${PORTNAME}-engines-2.16.1-1.fc10.src.rpm:SOURCE \
		gtk-murrine-engine-0.53.1-3.fc10.src.rpm:SOURCE \
		gtk-nodoka-engine-0.7.2-1.fc10.src.rpm:SOURCE \
		gtk-qt-engine-1.1-2.fc10.src.rpm:SOURCE \
		gtk-rezlooks-engine-0.6-6.fc9.src.rpm:SOURCE \
		gtk-xfce-engine-2.4.3-1.fc10.src.rpm:SOURCE \
		pixman-0.12.0-3.fc10.src.rpm:SOURCE \
		jasper-1.900.1-8.fc9.src.rpm:SOURCE

post-install:
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/gtk-2.0/modules/libferret.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/gtk-2.0/modules/libgail.la

.include <bsd.port.mk>
